class Solution {
    func numIslands(_ grid: [[Character]]) -> Int {
        var ans = 0
        var ngrid = grid
        let r = grid.count
        let c = grid[0].count
        
        let dx = [1, -1, 0, 0]
        let dy = [0, 0, 1, -1]
        
        for i in 0..<r {
            for j in 0..<c {
                if ngrid[i][j] == "1" {
                    var q = [(Int, Int)]()
                    
                    q.append((i, j))
                    ngrid[i][j] = "0"
                    while q.count != 0 {
                        let now = q[0]
                        q.removeFirst()
                        for k in 0..<4 {
                            let newr = now.0 + dx[k]
                            let newc = now.1 + dy[k]
                            
                            if newr < 0 || newr >= r || newc < 0 || newc >= c || ngrid[newr][newc] == "0" { continue }
                            ngrid[newr][newc] = "0"
                            q.append((newr, newc))
                        }
                    }
                    ans += 1
                }
            }
        }
        return ans
    }
}
