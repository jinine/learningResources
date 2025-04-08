import numpy as np

def main():
    # A multi-dimensional array in Python is typically represented using a list of lists (nested lists) 
    # or by using specialized libraries like NumPy for more efficient handling of arrays, especially for scientific computing.
    # 2D list (array with rows and columns)
    matrix = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]

    # Accessing elements
    print(matrix[0][1])  # 2 (first row, second column)

    # Creating a 2D NumPy array
    matrix = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])

    # Accessing elements
    print(matrix[0, 1])  # 2
if __name__=="__main__":
    main()
