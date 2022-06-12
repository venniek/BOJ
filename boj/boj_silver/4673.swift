var nums = [Int](repeating: 0, count: 10005)

func cons(n: Int) -> Int {
	var sum = n
	var now = n
	while now > 0 {
		sum += now % 10
		now /= 10
	}
	return sum
}

for i in 1...10000 {
	var now = i
	while now <= 10000 {
		if nums[now] == 1 { break }
		if now != i { nums[now] = 1 }
		now = cons(n: now)
	}
}
for i in 1...10000 {
	if nums[i] == 0 { print(i) }
}
