
## 二分搜索树: 简简单单，描述二叉树所有的性质

树结构可谓是计算机领域中最为重要的数据结构之一，B-Tree 与 B+Tree 几乎占据了数据库索引设计的全部江山。堆虽然由数组实现，但是这是因为完全二叉树特殊的结构导致，本质上仍然是一棵树。

之所以树结构应用如此广泛，是因为其在查找效率与内存空间使用上达到了几乎完美的平衡。

### 1. 二叉搜索树

对于一颗二叉搜索树而言，任意节点的左子树的值均小于它的根节点的值，右子树的值均大于或等于它的根节点的值，并且任意节点的左、右子树均为二叉搜索树。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/binary-search-tree/binary-search-tree.png)

如上图所示，两棵树都符合二叉搜索树的性质，尽管第二棵树看起来非常奇怪。不过，在后续的平衡二叉树中将会对第二棵看起来很奇怪的树进行优化，使得左右两棵子树的树高落差不会超过1。

#### 1.1 二分搜索树的API

除了最基本的查找、插入与删除节点等接口以外，树结构最为重要的接口就是遍历整颗二叉树。而对于二叉树的遍历而言，可分为广度优先遍历与深度优先遍历，这像极了程序员到底是选择首先扎根某一个领域，还是选择首先拓宽自己的知识边界。而深度优先遍历又可以分为前序遍历、中序遍历与后序遍历。

所以，相比于堆、栈等数据结构，二分搜索树所要实现的接口要更多一些。

```cpp
typedef struct node {
    int key;
    void *value;
    struct node *left;
    struct node *right;
} Node; 

typedef struct binary_tree {
    Node *root;
    size_t count;
} BinaryTree;

int find(BinaryTree *binary_tree, int find_key, Node *result);

int insert(BinaryTree *binary_tree, int key, void *value);

int update(BinaryTree *binary_tree, int key, void *value);

void delete(BinaryTree *binary_tree, int key);

void preorder(BinaryTree *binary_tree);

void midorder(BinaryTree *binary_tree);

void postorder(BinaryTree *binary_tree);

void levelorder(BinaryTree *binary_tree);
```

#### 1.2 二分搜索树元素的插入

当我们向二分搜索树中插入元素时，并不会向堆结构一样，改变原有树结构的元素排列，只会在某一个“空位”处插入节点，如下图所示：

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/binary-search-tree/insert.png)

因此，我们只需要找到待插入元素的前驱节点并插入即可：

```cpp
int insert(BinaryTree *binary_tree, int key, void *value) {

    Node *node = new_node(key, value);

    if (node == NULL) {
        return FAIL;
    }

    if (binary_tree->root == NULL) {
        binary_tree->root = node;
        binary_tree->count++;
        return SUCCESS;
    }

    Node *parrent;
    Node *current = binary_tree->root;
    
    while (current != NULL) {
        /*
         * 不断遍历，直到找到一个空节点为止，该空节点就是节点插入的位置，所以，我们还需要记录节点的父节点
         */
        parrent = current;

        if (key < current->key) {
            current = current->left;             // 当key小于当前节点值时，于左子树中进行查找
        } else if (key == current->key) {        // 当key等于当前节点值时，直接返回
            return;
        } else {
            current = current->right;           // 反之，则去右子树中查找
        }
    }

    if (key < parrent->key) {
        parrent->left = node;
    } else {
        parrent->right = node;
    }

    binary_tree->count++;
    
    return SUCCESS;
}
```

#### 1.2 二分搜索树元素的删除

删除二分搜索树中的某一个节点算是以上 API 中较为复杂的操作，首先我们先对最简单的情况进行分析，即待删除节点只有左子树或者是只有右子树的情况。

- 待删除节点只有左子树。此时只需要直接将待删除节点的左子树移到待删除节点的位置即可。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/binary-search-tree/delete-only-left.png)

- 待删除节点只有右子树。同“待删除节点只有左子树”的情况，将其右子树移到待删除节点的位置。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/binary-search-tree/delete-only-right.png)

剩下最为复杂的情况，待删除节点既有左子树，又有右子树，此时我们可以使用 Hibbard-Deletion 方法来删除该节点，该方法是 Thomas Hibbard 在 1962 年提出的，其核心思想就是找到一个待删除节点的前驱或者是后继节点来替换待删除节点，**前驱节点就是待删除节点左子树的最大值节点，后继节点为待删除节点右子树的最小值节点**。

如下图所示，假设待删除节点的 `key` 为 95，并将其标注为节点 `E`。如果按照后驱节点进行替换的方式删除节点 `E` 的话，那么大于节点 `E` 的且最接近的节点为 102。因此，只需要将 102 从右子树中删除，并移动到原有节点 `E` 的位置即可。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/binary-search-tree/delete_node.png)

前驱节点同理，找到待删除节点左子树中最大值，删除后移至待删除的节点位置即可。

```cpp
/*
 * 删除以 root 为根的二分搜索树的最小值，并返回删除后二分搜索树的根, 递归实现
 */
static Node *_delete_min(BinaryTree *binary_tree, Node *root) {
    if (root->left == NULL) {
        Node *right_node = root->right;
        
        root->right = NULL;         // 断开与原有二叉树的连接
        delete_node(root);

        binary_tree->count--;
        return right_node;
    }

    root->left = _delete_min(binary_tree, root->left);

    return root;
}

static Node *_delete(BinaryTree *binary_tree, Node *root, int key) {
    if (root == NULL) return NULL;

    if (key < root->key) {
        root->left = _delete(binary_tree, root->left, key);
        return root;
    }
    else if (key > root->key) {
        root->right = _delete(binary_tree, root->right, key);
        return root;
    }
    else {
        
        // 待删除节点左子树为空的情况
        if (root->left == NULL) {
            Node *right_node = root->right;

            root->right = NULL;         // 断开与原有二叉树的连接
            delete_node(root);

            binary_tree->count--;

            return right_node;
        }

        // 待删除节点右子树为空的情况
        else if (root->right == NULL) {
            Node *left_node = root->left;

            root->left = NULL;         // 断开与原有二叉树的连接
            delete_node(root);

            binary_tree->count--;

            return left_node;
        }

        // 既有左子树，又有右子树，使用 Hibbard-Deletion 删除
        Node *minium = new_node(0, NULL);
        get_min_value(binary_tree, &minium);
        minium->right = _delete_min(binary_tree, root->right);
        minium->left = root->left;

        return minium;
    }
}

void delete(BinaryTree *binary_tree, int key) {
    binary_tree->root = _delete(binary_tree, binary_tree->root, key);
}
```

C 语言描述 Hibbard-Deletion 还是比较麻烦的，Java 版的更加简洁一些，详见：

> http://math.oxford.emory.edu/site/cs171/hibbardDeletion/

### 1.3 二分搜索树的广度优先遍历

广度优先遍历又称之为层序遍历，从上之下、从左至右逐层地遍历二分搜索树的每一个节点，堆结构其实就是完全二叉树层序遍历后存储在数组中的，可非常方便地使用数组索引来表示某个节点的左、右孩子节点。

广度优先遍历通常需要借助先进先出队列的实现，首先根节点 Push 进队列，而后弹出处理，并将当前节点的左孩子、右孩子先后 Push 进队列。不断地重复上述过程即可得到二分搜索树的广度优先遍历。

```cpp
void levelorder(BinaryTree *binary_tree) {
    LinkedList *queue = new_linked_list();
    if (queue == NULL) return;

    Node *current_root = binary_tree->root;

    insert_linked_list_head(queue, "", current_root);

    char key[1];
    Node *process_node;

    printf("level order: ");

    while (!is_linked_list_empty(queue)) {
        process_node = pop_linked_list_tail(queue, key);

        printf("%d, ", process_node->key);

        if (process_node->left != NULL) {
            insert_linked_list_head(queue, "", process_node->left);
        }

        if (process_node->right != NULL) {
            insert_linked_list_head(queue, "", process_node->right);
        }
    }
    printf("\n");
}
```

### 1.3 二分搜索树的深度优先遍历

深度优先遍历又分为前序遍历、中序遍历与后序遍历，其中前序遍历按照“根节点-左子树-右子树”的顺序输出元素，中序遍历则按照“左子树-根节点-右子树”的顺序输出元素。

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/binary-search-tree/simple-tree.png)

对于上述的一棵二分搜索树而言，三种遍历方式的输出元素分别为：

- 前序遍历：`[80, 77, 60, 12, 65, 79, 95, 90, 109]`
- 中序遍历：`[12, 60, 65, 77, 79, 80, 90, 95, 109]`
- 后序遍历：`[12, 65, 60, 79, 77, 90, 109, 95, 80]`

可以看到，中序遍历其实就是有序地输出二分搜索树中的所有元素。递归实现这三种遍历方式比较简单，不再赘述。有趣的是非递归实现的前中序遍历与后序遍历。

下图为借助栈实现的中序遍历，元素入栈和出栈的时机设计地均相当巧妙：

![](https://smartkeyerror.oss-cn-shenzhen.aliyuncs.com/Snorlax/data-structure/binary-search-tree/midorder.png)

```cpp
void midorder(BinaryTree *binary_tree) {
    Stack *stack = new_stack(binary_tree->count, sizeof(Node *));
    if (stack == NULL) return;

    Node *current_root = binary_tree->root;

    push(stack, &current_root);

    Node *process_node;

    while (!is_stack_empty(stack)) {

        // 若当前节点的左孩子不为空的话，将其push进栈
        while (current_root->left != NULL) {
            push(stack, &current_root->left);
            current_root = current_root->left;
        }

        pop(stack, &process_node);
        printf("%d, ", process_node->key);

        // 若弹出的节点存在右子节点，则将其右孩子push进栈，并将右孩子作为新的root
        if (process_node->right != NULL) {
            push(stack, &process_node->right);
            current_root = process_node->right;
        }
    }
}
```
