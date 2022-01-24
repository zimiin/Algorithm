// 기둥과 보 설치

function solution(n, build_frame) {
  const col = [...Array(n + 1)].map(() => Array(n + 1).fill(0))
  const row = [...Array(n + 1)].map(() => Array(n + 1).fill(0))

  const checkRowCouldBeOn = (x, y) => {
    let res = false

    // 한쪽 끝 부분이 기둥 위에
    if (col[y - 1][x] === 1 || col[y - 1][x + 1] === 1) {
      res = true
    }
    // 양쪽 끝 부분이 다른 보와 연결
    else if (row[y][x - 1] === 1 && row[y][x + 1] === 1) {
      res = true
    }

    return res
  }

  const checkColCouldBeOn = (x, y) => {
    let res = false

    // 바닥이거나
    if (y === 0) {
      res = true
    }
    // 보의 한쪽 끝 위에 있거나
    else if (row[y][x] === 1 || row[y][x - 1] === 1) {
      res = true
    }
    // 다른 기둥 위
    else if (col[y - 1][x] === 1) {
      res = true
    }

    return res
  }

  const checkRowCouldBeRemoved = (x, y) => {
    let res = true

    row[y][x] = 0

    // 왼쪽 보
    if (row[y][x - 1]) {
      if (checkRowCouldBeOn(x - 1, y) === false) {
        res = false
      }
    }

    // 오른쪽 보
    if (row[y][x + 1]) {
      if (checkRowCouldBeOn(x + 1, y) === false) {
        res = false
      }
    }

    // 왼쪽 위 기둥
    if (col[y][x] === 1) {
      if (checkColCouldBeOn(x, y) === false) {
        res = false
      }
    }

    // 오른쪽 위 기둥
    if (col[y][x + 1] === 1) {
      if (checkColCouldBeOn(x + 1, y) === false) {
        res = false
      }
    }

    row[y][x] = 1

    return res
  }

  const checkColCouldBeRemoved = (x, y) => {
    let res = true

    col[y][x] = 0

    // 왼쪽 보
    if (row[y + 1][x - 1] === 1) {
      if (checkRowCouldBeOn(x - 1, y + 1) === false) {
        res = false
      }
    }

    // 오른쪽 보
    if (row[y + 1][x] === 1) {
      if (checkRowCouldBeOn(x, y + 1) === false) {
        res = false
      }
    }

    // 위 기둥
    if (col[y + 1][x] === 1) {
      if (checkColCouldBeOn(x, y + 1) === false) {
        res = false
      }
    }

    col[y][x] = 1

    return res
  }

  for (let frame of build_frame) {
    const [x, y, isRow, isAdd] = frame

    if (isAdd) {
      if (isRow) {
        if (checkRowCouldBeOn(x, y)) {
          row[y][x] = 1
        }
      } else {
        if (checkColCouldBeOn(x, y)) {
          col[y][x] = 1
        }
      }
    } else {
      if (isRow) {
        if (checkRowCouldBeRemoved(x, y)) {
          row[y][x] = 0
        }
      } else {
        if (checkColCouldBeRemoved(x, y)) {
          col[y][x] = 0
        }
      }
    }
  }

  const res = []

  for (let x = 0; x < n + 1; x++) {
    for (let y = 0; y < n + 1; y++) {
      if (col[y][x]) {
        res.push([x, y, 0])
      }
      if (row[y][x]) {
        res.push([x, y, 1])
      }
    }
  }

  return res
}