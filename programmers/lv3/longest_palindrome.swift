import Foundation

func solution(_ s:String) -> Int {  
    var str = Array(s)
    var start = 0
    var end = str.count - 1
    
    while end >= 0 {
        start = 0
        var nowend = end
        while nowend < str.count {
            var flag = true
            for i in 0...(nowend - start + 1) / 2 {
                if str[start + i] != str[nowend - i] {
                    flag = false
                    break
                }
            }
            if flag == true { 
                return nowend - start + 1 
            } else {
                start += 1
                nowend += 1
            }
        }
        end -= 1
    }

    return 1
}
