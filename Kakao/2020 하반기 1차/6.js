function solution(n, weak, dist) {
  const numFriends = dist.length
  const picked = Array(numFriends).fill(0)
  const checked = Array(weak.length).fill(0)
  const MAX = 1000
  let ans = MAX

  const getNextWeakIdx = (curWeakIdx, friendIdx) => {
    let canGo = dist[friendIdx]
    let before = weak[curWeakIdx]
    let i = curWeakIdx

    while (canGo >= 0) {
      let diff
      i = (i + 1) % weak.length

      if (before > weak[i]) {
        const tmp = weak[i] + n
        diff = tmp - before
      } else {
        diff = weak[i] - before
      }

      canGo -= diff
      before = weak[i]
    }

    return i
  }

  const cntFriends = (curIdx) => {
    if (checked[curIdx]) {
      console.log('picked', picked)
      console.log('checked', checked)
      return picked.reduce((prev, cur) => prev + cur)
    }

    let minFriends = MAX

    for (let friend = 0; friend < numFriends; friend++) {
      if (picked[friend]) {
        continue
      }
      console.log('friend', friend)
      const nextIdx = getNextWeakIdx(curIdx, friend)
      let checkCnt

      if (curIdx < nextIdx) {
        checkCnt = nextIdx - curIdx
      } else {
        checkCnt = (nextIdx + weak.length - curIdx) % weak.length
      }

      picked[friend] = 1
      for (let i = 0; i < checkCnt; i++) {
        const idx = (i + curIdx + weak.length) % weak.length
        checked[idx] = 1
      }

      minFriends = Math.min(minFriends, cntFriends(nextIdx))

      picked[friend] = 0
      for (let i = 0; i < checkCnt; i++) {
        const idx = (i + curIdx + weak.length) % weak.length
        checked[idx] = 0
      }
    }

    return minFriends
  }

  for (let startWeak = 0; startWeak < weak.length; startWeak++) {
    console.log('weak[startWeak]', weak[startWeak])
    ans = Math.min(ans, cntFriends(startWeak))
  }

  if (ans === MAX) {
    return -1
  } else {
    return ans
  }
}