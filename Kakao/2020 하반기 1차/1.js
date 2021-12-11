function solution(s) {
  if (s.length === 1) {
    return 1;
  }

  let longestUnit = s.length / 2;
  let answer = 1000;

  for (let unit = 1; unit <= longestUnit; unit++) {
    let before = s.slice(0, unit);
    let repeatCount = 1;
    let newLen = unit;

    for (let start = unit; start < s.length; start += unit) {
      let current = s.slice(start, start + unit);
      // console.log('before', before, 'current', current)

      if (before === current) {
        repeatCount++;
      } else {
        if (repeatCount !== 1) {
          newLen += repeatCount.toString().length;
        }

        before = current.slice();
        repeatCount = 1;
        newLen += before.length;
      }
      // console.log('before', before, 'current', current, 'repeatCount', repeatCount, 'newLen', newLen)
      // console.log()
    }

    if (repeatCount !== 1) {
      newLen += repeatCount.toString().length;
    }

    if (newLen < answer) {
      answer = newLen;
    }
  }

  return answer;
}