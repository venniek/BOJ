import Foundation

let nums = readLine()!.components(separatedBy: " ").map{ Int($0)! }
var eye = [0, 0, 0, 0, 0, 0, 0]
var ans = 0

for n in nums { eye[n] += 1 }
for i in (1...6).reversed() {
    if eye[i] == 0 { continue }
    else if eye[i] == 1 && ans == 0 { ans = i * 100 }
    else if eye[i] == 2 { 
        ans = 1000 + i * 100
        break
    } else if eye[i] == 3 {
        ans = 10000 + i * 1000
        break
    }
}
print(ans)
