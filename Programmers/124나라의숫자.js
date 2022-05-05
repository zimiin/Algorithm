function solution(n) {
  const digits = [];

  // 1, 2, 4 대신 0, 1, 2로 나타낸 결과 구하기
  for (let i = 0; 0 < n; i++) {
    // 현재 자릿수가 없는 부분 빼기
    n -= Math.pow(3, i);
    // 현재 자릿수보다 작은 경우
    if (n < 0) break;
    // 0, 1, 2 구하기
    const digit = Math.floor((n % Math.pow(3, i + 1)) / Math.pow(3, i));
    digits.push(digit);
  }

  // res 배열 뒤집기
  digits.reverse();

  // 0, 1, 2를 1, 2, 4로 바꾸기
  const res = digits
    .map((digit) => {
      if (digit === 0) {
        return 1;
      } else if (digit === 1) {
        return 2;
      } else {
        return 4;
      }
    })
    .join("");

  return res;
}
