function solution(board, r, c) {
    const used = Array(7).fill(false)
    let cards = new Set()
    const cardPos = {}
    
    board.forEach((row, i) => {
        row.forEach((cell, j) => {
            if (cell !== 0) {
                cards.add(cell)
                cardPos[cell] = cardPos[cell] || []
                cardPos[cell].push([i, j])    
            }
        })
    })
    
    cards = [...cards]
    
    const countKeyPressBetween = (from, to) => {
        const q = []
        const visited = [...Array(4)].map(() => Array(4).fill(false))
        const [nrPos, ncPos] = [[0, 0, 1, -1], [1, -1, 0, 0]]
        const inRange = (r, c) => (0 <= r && r < 4 && 0 <= c && c < 4)
        const arrived = (r, c) => (r === to[0] && c === to[1])

        q.push([from, 0])
        visited[from[0]][from[1]] = true
        
        while (q.length) {
            const [curPos, keyPress] = q.shift()
            
            if (arrived(curPos[0], curPos[1])) {
                return keyPress
            }
            
            for (let i = 0; i < 4; i++) {
                const nr = curPos[0] + nrPos[i]
                const nc = curPos[1] + ncPos[i]
                
                if (inRange(nr, nc) && !visited[nr][nc]) {
                    q.push([[nr, nc], keyPress + 1])
                    visited[nr][nc] = true
                }
                
                let ctrlR = curPos[0]
                let ctrlC = curPos[1]
                
                while (1) {
                    let nextR = ctrlR + nrPos[i]
                    let nextC = ctrlC + ncPos[i]
                    
                    if (!inRange(nextR, nextC)) {
                        if (!visited[ctrlR][ctrlC]) {
                            q.push([[ctrlR, ctrlC], keyPress + 1])
                            visited[ctrlR][ctrlC] = true
                        }
                        break
                    }
                    
                    if (board[nextR][nextC] > 0) {
                        if (!visited[nextR][nextC]) {
                            q.push([[nextR, nextC], keyPress + 1])
                            visited[nextR][nextC] = true
                        }
                        break
                    }
                    
                    ctrlR = nextR
                    ctrlC = nextC
                }
            }
        }
    }
    
    const countKeyPress = (order, depth, curPos, keyPress) => {
        if (depth === order.length) {
            return keyPress    
        }
        
        const card = order[depth]
        const [card1Pos, card2Pos] = cardPos[card]
        const [[c1r, c1c], [c2r, c2c]] = cardPos[card]
        
        const curKeyPress1 = countKeyPressBetween(curPos, card1Pos) + countKeyPressBetween(card1Pos, card2Pos) + 2
        const curKeyPress2 = countKeyPressBetween(curPos, card2Pos) + countKeyPressBetween(card2Pos, card1Pos) + 2
        
        board[c1r][c1c] = board[c2r][c2c] = 0
        const res = Math.min(countKeyPress(order, depth + 1, card2Pos, keyPress + curKeyPress1)
                             , countKeyPress(order, depth + 1, card1Pos, keyPress + curKeyPress2))
        board[c1r][c1c] = board[c2r][c2c] = card
        
        return res
    }
    
    return (function f(order) {
        if (order.length === cards.length) {
            return countKeyPress(order, 0, [r, c], 0)
        }
        
        let keyPress = 10000
        
        for (let i = 0; i < cards.length; i++) {
            const card = cards[i]
            
            if (used[card]) {
                continue
            }
            
            used[card] = true
            keyPress = Math.min(keyPress, f([...order, card]))
            used[card] = false
        }
        
        return keyPress
    })([])
}