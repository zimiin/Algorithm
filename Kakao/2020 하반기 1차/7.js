function solution(board) {
  const q = []
  const size = board.length
  const visited = [...Array(size)].map(() => [...Array(size)].map(() => [...Array(4)].fill(false)))
  const [rPos, cPos] = [[-1, 0, 1, 0], [0, 1, 0, -1]]

  const isArrived = (r, c, dir) => {
    if (r === size - 1 && c === size - 1) {
      return true
    } else if (r + rPos[dir] === size - 1 && c + cPos[dir] === size - 1) {
      return true
    } else {
      return false
    }
  }

  const getPosPair = (r, c, dir) => {
    return [[r, c], [r + rPos[dir], c + cPos[dir]]]
  }

  const isValidPos = (r, c, dir) => {
    const [[r1, c1], [r2, c2]] = getPosPair(r, c, dir)

    if (0 <= r1 && r1 < size && 0 <= c1 && c1 < size && 0 <= r2 && r2 < size && 0 <= c2 && c2 < size) {
      if (board[r1][c1] === 0 && board[r2][c2] === 0) {
        return true
      } else {
        return false
      }
    } else {
      return false
    }
  }

  const getNextPos = (r, c, dir) => {
    const res = []
    let [[r1, c1], [r2, c2]] = getPosPair(r, c, dir)

    // 방향을 아래 또는 오른쪽으로 맞추기
    if (dir === 0 || dir === 3) {
      [[r1, c1], [r2, c2]] = [[r2, c2], [r1, c1]]
      dir = dir === 0 ? 2 : 1
    }

    // 회전
    // 현재 방향 가로
    if (dir === 1) {
      if (0 < r1 && board[r1 - 1][c1] === 0 && board[r2 - 1][c2] === 0) {
        res.push([r1, c1, 0])
        res.push([r2, c2, 0])
      }
      if (r1 < size - 1 && board[r1 + 1][c1] === 0 && board[r2 + 1][c2] === 0) {
        res.push([r1, c1, 2])
        res.push([r2, c2, 2])
      }
    }
    // 현재 방향 세로
    else {
      if (0 < c1 && board[r1][c1 - 1] === 0 && board[r2][c2 - 1] === 0) {
        res.push([r1, c1, 3])
        res.push([r2, c2, 3])
      }
      if (c1 < size - 1 && board[r1][c1 + 1] === 0 && board[r2][c2 + 1] === 0) {
        res.push([r1, c1, 1])
        res.push([r2, c2, 1])
      }
    }

    // 4방향 이동
    for (let i = 0; i < 4; i++) {
      const [nr, nc] = [r1 + rPos[i], c1 + cPos[i]]
      if (isValidPos(nr, nc, dir)) {
        res.push([nr, nc, dir])
      }
    }

    return res
  }

  const isVisited = (r, c, dir) => {
    let [[r1, c1], [r2, c2]] = getPosPair(r, c, dir)

    // 방향을 아래 또는 오른쪽으로 맞추기
    if (dir === 0 || dir === 3) {
      [[r1, c1], [r2, c2]] = [[r2, c2], [r1, c1]]
      dir = dir === 0 ? 2 : 1
    }

    // 가로방향
    if (dir === 1) {
      if (visited[r1][c1][dir] || visited[r2][c2][3]) {
        return true
      } else {
        return false
      }
    } else {
      if (visited[r1][c1][dir] || visited[r2][c2][0]) {
        return true
      } else {
        return false
      }
    }
  }

  q.push([0, 0, 1, 0])
  visited[0][0][1] = true

  while (q.length > 0) {
    const [r, c, dir, dist] = q.shift()

    if (isArrived(r, c, dir)) {
      return dist
    }

    const nextPos = getNextPos(r, c, dir)

    for (let [nr, nc, nDir] of nextPos) {
      if (!isVisited(nr, nc, nDir)) {
        visited[nr][nc][nDir] = true
        q.push([nr, nc, nDir, dist + 1])
      }
    }
  }
}