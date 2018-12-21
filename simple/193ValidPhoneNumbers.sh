# https://leetcode-cn.com/problems/valid-phone-numbers/description/
# Read from the file file.txt and output all valid phone numbers to stdout.
# grep with Regex
cat file.txt | grep -P  '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$'