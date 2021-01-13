
#include <vector>

using namespace std;

/*
 * 顺时针旋转图像 90°，在日常的图片预览等应用中使用非常频繁。
 * 
 * 这里是顺时针旋转 90°，其实我们可以旋转 45°，25° 等等等等。熟悉 Python 的小伙伴儿可以看看 pillow 库中的实现
 * 
 * from PIL import Image
 * 
 * image = Image.open("avatar.jpg")
 * image_rotate = image.rotate(45)
 * image_rotate = image.rotate(-45)
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                swap(matrix[i][j], matrix[j][i]);
        
        for (int i = 0; i < matrix.size(); i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};