class Solution {
    func backspaceCompare(_ s: String, _ t: String) -> Bool {
        var forS:String = ""
        var forT: String = ""
        let news = Array(s)
        let newt = Array(t)
        
        for i in 0..<news.count {
            if news[i] != "#" {
                forS.append(news[i])
            } else if forS.count != 0 {
                forS.removeLast()
            }
        }
        for i in 0..<newt.count {
            if newt[i] != "#" {
                forT.append(newt[i])
            } else if forT.count != 0 {
                forT.removeLast()
            }
        }
        return forS == forT
    }
}

