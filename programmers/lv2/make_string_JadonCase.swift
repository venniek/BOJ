func solution(_ s:String) -> String {
    var str = Array(s.lowercased())
    for i in 0..<str.count {
        if i == 0 || str[i] != " " && str[i - 1] == " " {
            str[i] = Character(str[i].uppercased())
        }
    }
    return String(str)
}
