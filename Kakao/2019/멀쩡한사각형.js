function solution(w, h) {
  const getGCD = (a, b) => {
    while (0 < b) {
      [a, b] = [b, a % b];
    }
    return a;
  };

  // 최대공약수 구하기
  const gcd = getGCD(w, h);
  // 가장 작은 단위 구하기
  const [sw, sh] = [w / gcd, h / gcd];
  // 가장 작은 단위에서 사용하지 못하는 사각형 수 구하기
  const unusable = sw + sh - 1;
  // w * h - 최대공약수 * 사용 못하는 사각형 수 반환
  return w * h - gcd * unusable;
}
