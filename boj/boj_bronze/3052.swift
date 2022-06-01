var nums = Set<Int>()

for _ in 1...10 {
	nums.insert(Int(readLine()!)! % 42)
}
print(nums.count)
