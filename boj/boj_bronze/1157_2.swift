let str = readLine()!.uppercased()
var dic = [Character: Int]()

for c in str {
	if let tmp = dic[c] { dic[c] = tmp + 1} 
    else { dic[c] = 1 }
}
if dic.count > 1 {
	let sorteddic = dic.sorted{ $0.1 > $1.1 }
	if sorteddic[0].value == sorteddic[1].value { print("?") } 
	else { print(sorteddic[0].key) }
} else {
	print(str.prefix(1))
}

