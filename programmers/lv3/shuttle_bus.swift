import Foundation

func timeToString(_ time: Int) -> String {
    let h = time / 60
    let m = time % 60
    var ans = ""

    ans += (h < 10 ? "0" : "") + String(h) + ":"
    ans += (m < 10 ? "0" : "") + String(m)

    return ans
}

func solution(_ n:Int, _ t:Int, _ m:Int, _ timetable:[String]) -> String {
    var crews = timetable.map{ Int($0.prefix(2))! * 60 + Int($0.suffix(2))! }.sorted()
    var lasttime = 0
    var vacancy = m
    var nowtime = 540
    
    for _ in 0..<n {
        vacancy = m
        while vacancy > 0 && !crews.isEmpty {
            if crews[0] <= nowtime {
                lasttime = crews.removeFirst()
                vacancy -= 1
            } else {
                break
            }
        }
        nowtime += t
    }
    if vacancy == 0 {
        return timeToString(lasttime - 1)
    }
    return timeToString(nowtime - t)
}
