class Solution:
    def generate(self, num_rows: int) -> list[list[int]]:
        result = [[1]]

        for _ in range(num_rows - 1):
            new_row = result[-1] + [1]
            new_row_copy = new_row.copy()
            for i in range(1, len(new_row) - 1):
                new_row[i] += new_row_copy[i - 1]
            result.append(new_row)
        return result
        