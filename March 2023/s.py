l = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
flatten = []
for element in l:
    for inner_element in element:
        flatten.append(inner_element)
print(flatten)
