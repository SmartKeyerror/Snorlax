
class Solution(object):
    def __init__(self):
        self.row = [set() for _ in range(9)]
        self.col = [set() for _ in range(9)]
        self.cell = [set() for _ in range(9)]

    def init(self, board):
        for i in range(9):
            for j in range(9):
                val = board[i][j]
                if val == ".":
                    continue
                self.row[i].add(val)
                self.col[j].add(val)
                self.cell[(i // 3) * 3 + j // 3].add(val)

    def is_valid(self, i, j, val):
        if val in self.row[i]:
            return False
        if val in self.col[j]:
            return False
        if val in self.cell[(i // 3) * 3 + j // 3]:
            return False
        return True

    def backtracking(self, board, i, j):
        if j == 9:
            i += 1
            j = 0

        if i == 9:
            return True

        if board[i][j] != ".":
            return self.backtracking(board, i, j + 1)

        for k in range(1, 10):
            val = str(k)

            if not self.is_valid(i, j, val):
                continue

            board[i][j] = val
            self.row[i].add(val)
            self.col[j].add(val)
            self.cell[(i // 3) * 3 + j // 3].add(val)

            if self.backtracking(board, i, j + 1):
                return True

            board[i][j] = "."
            self.row[i].remove(val)
            self.col[j].remove(val)
            self.cell[(i // 3) * 3 + j // 3].remove(val)

        return False

    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        self.init(board)
        self.backtracking(board, 0, 0)


if __name__ == "__main__":
    board = [["5", "3", ".", ".", "7", ".", ".", ".", "."],
             ["6", ".", ".", "1", "9", "5", ".", ".", "."],
             [".", "9", "8", ".", ".", ".", ".", "6", "."],
             ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
             ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
             ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
             [".", "6", ".", ".", ".", ".", "2", "8", "."],
             [".", ".", ".", "4", "1", "9", ".", ".", "5"],
             [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
    Solution().solveSudoku(board)
    print(board)