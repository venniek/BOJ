var nums = [Int](repeating: 0, count: 10005)

func cons(n: Int) -> Int {
	var sum = 0
	var now = n
	while now > 0 {
		sum += now
		now /= 10
	}
	return sum
}

for i in 1...10000 {
	var now = i
	var flag = 0
	while now < 10000 {
		if nums[now] == 1 {
			break
		}
		if flag != 0 { nums[now] = 1 }
		now = cons(n: now)
		flag += 1
	}
}
for i in 1...10000 {
	if nums[i] == 0 { print(i) }
}
