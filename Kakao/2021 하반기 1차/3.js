// 2021 KAKAO BLIND RECRUITMENT 3번 순위 검색

let scoresInGroup = {}

function addScoreToGroup(group, score, groupIdx) {
  if (groupIdx >= group.length) {
    let key = group.join('')

    if (scoresInGroup[key]) {
      scoresInGroup[key].push(score)
    } else {
      scoresInGroup[key] = [score]
    }

    return
  }

  addScoreToGroup(group, score, groupIdx + 1)
  let newGroup = [...group]
  newGroup[groupIdx] = '-'
  addScoreToGroup(newGroup, score, groupIdx + 1)
}

function addScore(info) {
  let group = info.split(' ')
  let score = parseInt(group.pop())

  addScoreToGroup(group, score, 0)
}

function findScoreIdx(scores, score) {
  let s = 0
  let e = scores.length - 1
  let m
  let idx = -1

  while (s <= e) {
    m = Math.floor((s + e) / 2)

    if (scores[m] < score) {
      idx = m
      s = m + 1
    } else {
      e = m - 1
    }
  }

  return idx + 1
}

function countScoresInGroup(group, score) {
  let key = group.join('')
  let scores = scoresInGroup[key]

  if (scores === undefined) {
    return 0
  } else {
    let start = findScoreIdx(scores, score)
    return scores.length - start
  }
}

function solution(info, query) {
  // make group-score data
  for (let participantInfo of info) {
    addScore(participantInfo)
  }

  // sort scores in every group
  for (let key in scoresInGroup) {
    scoresInGroup[key].sort((a, b) => a - b)
  }

  let result = []

  // answer query
  for (let q of query) {
    let group = q.replace(/ and /g, ' ').split(' ')
    let score = parseInt(group.pop())

    let answer = countScoresInGroup(group, score)
    result.push(answer)
  }

  return result
}