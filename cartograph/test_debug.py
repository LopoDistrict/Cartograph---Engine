# Read the file
file_path = "exe/limite.flag"
with open(file_path, "r") as file:
    lines = file.readlines()

# Process each line
first_line_values = lines[0].split(":") #on doit changer le 0
second_value = int(first_line_values[1])
third_value = int(first_line_values[2])

# Check if the third value is greater than the second value
if third_value < second_value:
    third_value += 1

# Modify the first line with the updated third value
first_line_values[2] = str(third_value)
lines[0] = ":".join(first_line_values) + "\n"#on doit changer le 0 sale fdp 

# Write the modified content back to the file
with open(file_path, "w") as file:
    file.writelines(lines)
