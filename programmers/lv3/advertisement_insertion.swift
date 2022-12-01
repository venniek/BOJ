import Foundation

func solution(_ play_time:String, _ adv_time:String, _ logs:[String]) -> String {
    func addTimeString(_ time: Int) -> String {
        return (time < 10 ? "0" : "") + String(time)
    }
    func timeToInt(_ str: String) -> Int {
        let times = str.components(separatedBy: ":").map{ Int($0)! }
        return times[0] * 3600 + times[1] * 60 + times[2]
    }
    func timeToString(_ time: Int) -> String {
        return addTimeString(time / 3600) + ":" 
            + addTimeString(time % 3600 / 60) + ":"
            + addTimeString(time % 3600 % 60)
    }
    
    let playtime = timeToInt(play_time)
    let advtime = timeToInt(adv_time)
    var sumtime = [Int64](repeating: 0, count: playtime + 1)
    var maxtime:Int64 = 0
    var ans = 0
    
    for l in logs {
        let start = timeToInt(String(l.prefix(8)))
        let end = timeToInt(String(l.suffix(8)))
        sumtime[start] += 1
        sumtime[end] -= 1
    }
    for i in 1..<sumtime.count {
        sumtime[i] += sumtime[i - 1]
    }
    var tmpsum:Int64 = sumtime[0...advtime - 1].reduce(0, +)
    maxtime = tmpsum
    for i in advtime..<sumtime.count - 1 {
        tmpsum += sumtime[i] - sumtime[i - advtime]
        if tmpsum > maxtime {
            ans = i - advtime + 1
            maxtime = tmpsum
        }
    }
    
    return timeToString(ans)
}
