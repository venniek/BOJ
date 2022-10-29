import Foundation

func solution(_ sticker:[Int]) -> Int{
    let len = sticker.count
    var noFirst = [[Int]](repeating: [Int](repeating: 0, count: 2), count: len - 1)
    var yesFirst = [[Int]](repeating: [Int](repeating: 0, count: 2), count: len - 1)
    
    if len == 1 {
        return sticker[0]
    }
    
    noFirst[0][0] = 0
    noFirst[0][1] = sticker[1]
    yesFirst[0][0] = sticker[0]
    yesFirst[0][1] = sticker[0]
    
    for i in 1..<len - 1 {
        noFirst[i][0] = noFirst[i - 1].max()!
        noFirst[i][1] = noFirst[i - 1][0] + sticker[i + 1]
        yesFirst[i][0] = yesFirst[i - 1].max()!
        yesFirst[i][1] = yesFirst[i - 1][0] + sticker[i + 1]   
    }
    
    return max(noFirst[len - 2].max()!, yesFirst[len - 2][0])
}
