import Foundation

func solution(_ keymap:[String], _ targets:[String]) -> [Int] {
    var dict = [Character: Int]()
    var ans = [Int]()
    
    for key in keymap {
        let maxLength = key.count + 1
        for (i, char) in key.enumerated() {
            let value = min(dict[char] ?? maxLength, i + 1)
            dict[char] = value
        }
    }
    
    for target in targets {
        var cnt = 0
        for char in target {
            guard let value = dict[char] else {
                cnt = -1
                break
            }
            cnt += value
        }
        ans.append(cnt)
    }
    
    return ans
}
