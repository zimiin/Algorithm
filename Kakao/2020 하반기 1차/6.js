function solution(n, weak, dist) {
  const numFriends = dist.length
  const longWeak = Array(weak.length * 2)
  const picked = Array(numFriends).fill(0)
  const MAX = 1000

  for (let i = 0; i < weak.length; i++) {
    longWeak[i] = weak[i]
    longWeak[i + weak.length] = weak[i] + n
  }

  const getNextWeakIdx = (curWeakIdx, friendIdx) => {
    const canGo = dist[friendIdx]
    const finalPos = longWeak[curWeakIdx] + canGo
    let i

    for (i = curWeakIdx + 1; i < longWeak.length; i++) {
      if (finalPos < longWeak[i]) {
        break
      }
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

  let ans = MAX

  for (let startWeak = 0; startWeak < weak.length; startWeak++) {
    ans = Math.min(ans, cntFriends(startWeak, startWeak))
  }

  if (ans === MAX) {
    return -1
  } else {
    return ans
  }
}