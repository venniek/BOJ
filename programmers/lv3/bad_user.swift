import Foundation

func solution(_ user_id:[String], _ banned_id:[String]) -> Int {
    
    var candi = [[String]](repeating: [String](), count: banned_id.count)
    var list = Set<Set<String>>()
    
    // func - 가능한 이름 찾는 함수
    func isSame(_ s1: [Character], _ s2: [Character]) -> Bool {
        if s1.count != s2.count { return false }
        for i in 0..<s1.count {
            if s1[i] != s2[i] && s1[i] != "*" { return false }
        }
        return true
    }

    // func - 가능한 조합 만들어서 Set에 넣기
    func insertGroup(_ tmpSet: Set<String>, _ idx: Int, _ str: String) {
        var newSet = tmpSet
        
        if newSet.contains(str) { return }
        if str != "" { newSet.insert(str) }
        
        if idx == banned_id.count {
            list.insert(newSet)
            return 
        }
        
        for can in candi[idx] {
            insertGroup(newSet, idx + 1, can)
        }
    }
    
    // 가린 이름 별로 가능한 이름 다 찾기
    for bi in 0..<banned_id.count {
        for u in user_id {
            if isSame(Array(banned_id[bi]), Array(u)) {
                candi[bi].append(u)
            }
        }
    }

    insertGroup(Set<String>(), 0, "")

    return list.count
}
