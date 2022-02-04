function solution(n, info) {
  let answer = [-1]
  let scoreDiff = -1
  const ryanArrow = Array(11).fill(0)

  const getRyanApeachScore = (ryanArrow, apeachArrow) => {
    let ryan = 0
    let apeach = 0

    for (let i = 0; i < 11; i++) {
      if (info[i] < ryanArrow[i]) {
        ryan += 10 - i
      } else if (0 < apeachArrow[i]) {
        apeach += 10 - i
      }
    }

    return [ryan, apeach]
  }

  const getAnswer = (curAnswer, newAnswer) => {
    for (let i = 10; 0 <= i; i--) {
      if (curAnswer[i] < newAnswer[i]) {
        return [...newAnswer]
      } else if (curAnswer[i] > newAnswer[i]) {
        return [...curAnswer]
      }
    }
    return [...curAnswer]
  }

  const recur = (idx, remainArrow) => {
    if (11 <= idx || remainArrow === 0) {
      const [ryan, apeach] = getRyanApeachScore(ryanArrow, info)
      const diff = ryan - apeach

      if (0 < diff) {
        if (scoreDiff < diff) {
          scoreDiff = diff
          answer = [...ryanArrow]
        } else if (scoreDiff === diff) {
          answer = getAnswer(answer, ryanArrow)
        }
      }

      return
    }

    for (let arrow = remainArrow; 0 <= arrow; arrow--) {
      ryanArrow[idx] = arrow
      recur(idx + 1, remainArrow - arrow)
    }
  }

  recur(0, n)

  return answer
}