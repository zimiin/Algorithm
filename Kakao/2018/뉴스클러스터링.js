function solution(str1, str2) {
  const hasNonAlphabet = (str) => {
    const regex = new RegExp("[\\W\\d_]");
    return regex.test(str);
  };

  const getSet = (str) => {
    const res = [];
    for (let i = 0; i < str.length - 1; i++) {
      const elem = str.slice(i, i + 2);
      if (hasNonAlphabet(elem)) continue;
      res.push(elem);
    }
    return res;
  };

  // 모두 소문자로 변환
  str1 = str1.toLowerCase();
  str2 = str2.toLowerCase();

  // 문자열의 다중집합
  const [set1, set2] = [getSet(str1), getSet(str2)];

  // 둘 다 공집합일 경우
  if (set1.length === 0 && set2.length === 0) {
    return 65536;
  }

  // 유사도 계산시 사용되었던 set2 element인지
  const usedElem = Array(set2.length).fill(false);
  // 교집합 크기
  let intersec = 0;

  for (const e of set1) {
    // 교집합인지 확인
    for (let i = 0; i < set2.length; i++) {
      if (e === set2[i] && !usedElem[i]) {
        intersec++;
        usedElem[i] = true;
        break;
      }
    }
  }

  const similarity = intersec / (set1.length + set2.length - intersec);
  const answer = Math.floor(similarity * 65536);
  return answer;
}
