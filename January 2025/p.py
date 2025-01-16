import random

def generate_test_case():
    # Define the size of the arrays
    size = 10**5

    # Define the range of numbers
    min_value = 10**7
    max_value = 10**9

    # Generate the two arrays
    nums1 = [random.randint(min_value, max_value) for _ in range(size)]
    nums2 = [random.randint(min_value, max_value) for _ in range(size)]

    return nums1, nums2

# Generate the test case
nums1, nums2 = generate_test_case()

# Save the arrays to a file for later use
with open("test_case.txt", "w") as f:
    f.write(f"nums1: {nums1}\n")
    f.write(f"nums2: {nums2}\n")

print("Test case generated and saved to test_case.txt.")