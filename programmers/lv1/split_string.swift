import Foundation

func solution(_ s:String) -> Int {
    let str = Array(s)
    var ans = 0
    var flag = 0
    var now: Character = str[0]
    
    for i in 0..<str.count {
        if flag == 0 {
            now = str[i]
            flag = 1
        } else {
            flag += (str[i] == now ? 1 : -1)
        }
        
        if flag == 0 {
            ans += 1
        }
    }

    return ans + (flag != 0 ? 1 : 0)
}
