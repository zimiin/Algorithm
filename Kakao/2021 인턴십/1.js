function solution(s) {
  let answer = '';

  for (let idx = 0; idx < s.length;) {
    const curChar = s.charAt(idx);
    const nextChar = s.charAt(idx + 1);

    if ('0' <= curChar && curChar <= '9') {
      answer += curChar;
      idx++;
    } else {
      switch (curChar) {
        case 'z':
          answer += '0';
          idx += 4;
          break;
        case 'o':
          answer += '1';
          idx += 3;
          break;
        case 't':
          if (nextChar === 'w') {
            answer += '2';
            idx += 3;
          } else {
            answer += '3';
            idx += 5;
          }
          break;
        case 'f':
          if (nextChar === 'o') {
            answer += '4';
            idx += 4;
          } else {
            answer += '5';
            idx += 4;
          }
          break;
        case 's':
          if (nextChar === 'i') {
            answer += '6';
            idx += 3;
          } else {
            answer += '7';
            idx += 5;
          }
          break;
        case 'e':
          answer += '8';
          idx += 5;
          break;
        default:
          answer += '9';
          idx += 4;
      }
    }
  }

  return Number.parseInt(answer);
}