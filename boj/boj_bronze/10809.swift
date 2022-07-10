let s = readLine()!
for c in "abcdefghijklmnopqrstuvwxyz"{
    var index: Int
    if let tmp = s.firstIndex(of: c) {
		index = s.distance(from: s.startIndex, to: tmp)
	} else {
		index = -1
    }
    print(index, terminator: " ")
}