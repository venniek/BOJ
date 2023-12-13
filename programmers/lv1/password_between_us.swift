import Foundation

func solution(_ s:String, _ skip:String, _ index:Int) -> String {
    var alpha = Array("abcdefghijklmnopqrstuvwxyz").filter { !skip.contains(String($0)) }
    var str = ""
    
    for c in s {
        let finalIndex = (alpha.index(of: c)! + index) % alpha.count
        str += String(alpha[finalIndex])
    }
    
    return str
}
