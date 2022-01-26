function solution(n, weak, dist) {
  const numFriends = dist.length
  const longWeak = Array(weak.length * 2)
  const picked = Array(numFriends).fill(0)
  const MAX = 1000
  let ans = MAX

  for (let i = 0; i < weak.length; i++) {
    longWeak[i] = weak[i]
    longWeak[i + weak.length] = weak[i] + n
  }

  const getNextWeakIdx = (curWeakIdx, friendIdx) => {
    let canGo = dist[friendIdx]
    let before = longWeak[curWeakIdx]
    let i = curWeakIdx

    while (canGo >= 0) {
      let diff
      i++

      if (i >= longWeak.length) {
        return i
      }

      diff = longWeak[i] - before

      canGo -= diff
      before = longWeak[i]
    }

    return i
  }

  const cntFriends = (startIdx, curIdx) => {
    if (curIdx - startIdx >= weak.length) {
      return picked.reduce((prev, cur) => prev + cur)
    }

    let minFriends = MAX

    for (let friend = 0; friend < numFriends; friend++) {
      if (picked[friend]) {
        continue
      }

      const nextIdx = getNextWeakIdx(curIdx, friend)

      picked[friend] = 1
      minFriends = Math.min(minFriends, cntFriends(startIdx, nextIdx))
      picked[friend] = 0
    }

    return minFriends
  }

  for (let startWeak = 0; startWeak < weak.length; startWeak++) {
    ans = Math.min(ans, cntFriends(startWeak, startWeak))
  }

  if (ans === MAX) {
    return -1
  } else {
    return ans
  }
}