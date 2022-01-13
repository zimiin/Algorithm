// 괄호 변환

function validStr(str) {
  let stack = []

  for (let i = 0; i < str.length; i++) {
    if (str.charAt(i) === '(') {
      stack.push('(')
    } else {
      if (stack.length < 1) {
        return false
      }
      stack.pop()
    }
  }

  if (stack.length === 0) {
    return true
  } else {
    return false
  }
}

function getAnswer(str) {
  if (str.length === 0) {
    return str
  }

  // get u
  let cntOpen = 0
  let cntClose = 0
  let idx = 0

  for (; idx < str.length; idx++) {
    if (str.charAt(idx) == '(') {
      cntOpen++
    } else {
      cntClose++
    }

    if (cntOpen === cntClose) {
      break
    }
  }

  const u = str.substr(0, idx + 1)
  const v = str.substr(idx + 1)

  if (validStr(u)) {
    return u + getAnswer(v)
  }

  let resStr = '(' + getAnswer(v) + ')'

  // reverse u
  for (let i = 1; i < u.length - 1; i++) {
    if (u.charAt(i) === '(') {
      resStr += ')'
    } else {
      resStr += '('
    }
  }

  return resStr
}

function solution(p) {
  let answer = getAnswer(p)
  return answer
}