// 후보키

function solution(relation) {
  const columnCnt = relation[0].length
  const candidateKeys = []

  const getKey = (indexes) => {
    let key = ''

    for (let index of indexes) {
      key += index
    }

    return key
  }

  const recur = (keys, indexes, index, len, cnt) => {
    if (len === cnt) {
      keys.push(getKey(indexes))
      return
    }

    if (index >= columnCnt) {
      return
    }

    indexes.push(index)
    recur(keys, indexes, index + 1, len, cnt + 1)
    indexes.pop()
    recur(keys, indexes, index + 1, len, cnt)
  }

  const isUnique = (key) => {
    const map = new Map()
    const indexes = [...key].map((e) => parseInt(e))

    for (let r of relation) {
      let k = ''
      for (let i of indexes) {
        k += r[i]
      }

      if (map.get(k)) {
        return false
      } else {
        map.set(k, true)
      }
    }

    return true
  }

  const isMinimal = (key) => {
    for (let ck of candidateKeys) {
      let cnt = 0

      for (let i = 0; i < ck.length; i++) {
        const res = key.search(ck.charAt(i))
        if (res > -1) {
          cnt++
        }
      }

      if (cnt === ck.length) {
        return false
      }
    }
    return true
  }

  for (let len = 1; len <= columnCnt; len++) {
    const keys = []
    // const recur = (keys, indexes, index, len, cnt) => {}
    recur(keys, [], 0, len, 0)

    const minimalKeys = []

    for (let key of keys) {
      if (isMinimal(key)) {
        minimalKeys.push(key)
      }
    }

    for (let mk of minimalKeys) {
      if (isUnique(mk)) {
        candidateKeys.push(mk)
      }
    }
  }

  return candidateKeys.length
}