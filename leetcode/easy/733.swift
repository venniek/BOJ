class Solution {
    func floodFill(_ image: [[Int]], _ sr: Int, _ sc: Int, _ color: Int) -> [[Int]] {
        let dx = [0, 0, 1, -1]
        let dy = [1, -1, 0, 0]
        var done = [[Int]](repeating: Array(repeating: 0, count: image[0].count), count: image.count)
        var newImage: [[Int]] = image
        var c = image[sr][sc]
        var q = [(Int, Int)]()
        
        q.append((sr, sc))
        while q.count > 0 {
            let now = q[0]
            newImage[now.0][now.1] = color
            done[now.0][now.1] = 1
            q.removeFirst()
            for i in 0..<4 {
                let newr = now.0 + dx[i]
                let newc = now.1 + dy[i]
                if newr < 0 || newr >= image.count || newc < 0 || newc >= image[0].count {
                    continue;   
                }
                if done[newr][newc] == 0 && newImage[newr][newc] == c {
                     q.append((newr, newc))
                }
            }
        }
        return newImage
    }
}
