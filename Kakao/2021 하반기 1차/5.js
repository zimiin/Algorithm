// 2021 KAKAO BLIND RECRUITMENT 카드 짝 맞추기

const BOARD = new Array(4)
let isRemainCard = new Array(7)
let cardPos = new Array(7)
let answer = 0

function noRemainCard() {
  let foundRemainCard = false

  for (let i = 1; i < 7; i++) {
    if (isRemainCard[i]) {
      foundRemainCard = true
      break
    }
  }

  if (foundRemainCard) {
    return false
  } else {
    return true
  }
}

function countKeyPressBetween(pos1, pos2) {
  const r1 = pos1[0]
  const c1 = pos1[1]
  const r2 = pos2[0]
  const c2 = pos2[1]
  const startR = Math.min(r1, r2)
  const endR = Math.max(r1, r2)
  const startC = Math.min(c1, c2)
  const endC = Math.max(c1, c2)
  let keyPress = 0

  // row first
  let cnt = 0
  let beforeR = startR

  for (let r = startR; r < endR;) {
    let nextR
    let hadACard = false

    for (nextR = r + 1; nextR < endR; nextR++) {
      let curCard = BOARD[nextR][c1]
      if (isRemainCard[curCard]) {
        hadACard = true
        break
      }
    }

    if (hadACard) {
      cnt++
      beforeR = nextR
      r = nextR
      continue
    } else if (endR === 3) {
      cnt++
      break
    } else if (nextR === endR) {
      cnt += endR - beforeR
    }
  }

  for (let c = startC + 1; c <= endC; c++) {
    let curCard = BOARD[r2][c]
    if (isRemainCard[curCard]) {
      cnt++
    }
  }

  keyPress = cnt

  // col first
  cnt = 0
  let beforeC = startC

  for (let c = startC; c < endC;) {
    let nextC
    let hadACard = false

    for (nextC = c + 1; nextC < endC; nextC++) {
      let curCard = BOARD[r1][nextC]
      if (isRemainCard[curCard]) {
        hadACard = true
        break
      }
    }

    if (hadACard) {
      cnt++
      beforeC = nextC
      c = nextC
      continue
    } else if (endC === 3) {
      cnt++
      break
    } else if (nextC === endC) {
      cnt += endC - beforeC
    }
  }

  for (let r = startR + 1; r <= endR; r++) {
    let curCard = BOARD[r][c2]
    if (isRemainCard[curCard]) {
      keyPress++
    }
  }

  keyPress = keyPress < cnt ? keyPress : cnt

  return keyPress
}

function countKeyPress(curPos, nextPos, finalPos) {
  return countKeyPressBetween(curPos, nextPos) + countKeyPressBetween(nextPos, finalPos) + 2
}

function recur(r, c, keyPress) {
  if (noRemainCard()) {
    if (answer === 0) {
      answer = keyPress
    } else if (keyPress < answer) {
      answer = keyPress
    }
  }

  for (let i = 1; i < 7; i++) {
    if (isRemainCard[i] === false) {
      continue
    }

    isRemainCard[i] = false

    let curKeyPress = keyPress + countKeyPress([r, c], cardPos[0], cardPos[1])
    recur(cardPos[1][0], cardPos[1][1], curKeyPress)

    curKeyPress = keyPress + countKeyPress([r, c], cardPos[1], cardPos[0])
    recur(cardPos[0][0], cardPos[0][1], curKeyPress)

    isRemainCard[i] = true
  }
}

function solution(board, r, c) {
  for (let i = 0; i < 7; i++) {
    remainCards[i] = false
  }

  for (let i = 0; i < 4; i++) {
    BOARD[i] = new Array(4)

    for (let j = 0; j < 4; j++) {
      BOARD[i][j] = board[i][j]

      if (board[i][j] !== 0) {
        let cur = board[i][j]
        isRemainCard[cur] = true
        cardPos.push([i, j])
      }
    }
  }

  recur(r, c, 0)

  return answer
}