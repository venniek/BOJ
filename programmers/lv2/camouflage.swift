import Foundation

func solution(_ clothes:[[String]]) -> Int {
    var dict = [String: Int]()
    var ans = 1
    
    for str in clothes {
        if let cnt = dict[str[1]] {
            dict[str[1]] = cnt + 1
        } else {
            dict[str[1]] = 1
        }
    }
    for i in dict {
        ans *= i.value + 1
    }
    
    return ans - 1
}
