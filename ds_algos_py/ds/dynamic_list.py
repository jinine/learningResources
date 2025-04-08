def main():
    # this is an implementation of dynamic lists 
    # Because Python lists are dynamic, they can grow or shrink based on the number of elements. 
    my_list = [1, 2, 3]
    my_list.append(4)
    my_list.insert(5, 5)  # Inserts 5 at index 5
    my_list.extend([6, 7])  # Adds [4, 5] to the end
    last_item = my_list.pop()  # Removes and returns the last element (7)
    my_list.remove(6)  # Removes the first occurrence of 6
    print(my_list)

    my_list.clear()  # Clears the list
    print(my_list)  # []

if __name__=="__main__":
    main()
