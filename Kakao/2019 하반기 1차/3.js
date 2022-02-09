// 후보키

function solution(relation) {
  let answer = 0
  const keys = new Map()
  const inKey = new Array(relation.length)

  for (let i = 0; i < inKey.length; i++) {
    inKey[i] = false
  }

  const getKey = () => {
    let key = ''

    for (let i = 0; i < inKey.length; i++) {
      if (inKey[i]) {
        key += i
      }
    }

    return key
  }

  const isUnique = (key) => {
    const indexes = [...key].map((e) => parseInt(e))
    const map = new Map()

    for (let i = 0; i < relation.length; i++) {
      let k = ''

      for (let index of indexes) {
        key += relation[i][index]
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

  }

  (function recur(index) {
    if (index === relation.length) {
      const key = getKey()
      if (key === '') {
        return
      }
      if (isUnique(key) && isMinimal(key)) {
        answer++
      }
      return
    }

    inKey[index] = true
    recur(index + 1)
    inKey[index] = false
    recur(index + 1)
  })(0);

  return answer
}