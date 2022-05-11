function solution(enroll, referral, seller, amount) {
  const parent = {}; // child -> parent
  const totalAmt = {}; // person -> total amount array

  // parent 그래프 만들기
  for (let i = 0; i < enroll.length; i++) {
    const p = referral[i];
    const c = enroll[i];
    parent[c] = p;
  }

  // totalAmt 초기화
  totalAmt["-"] = 0;
  for (const person of enroll) {
    totalAmt[person] = 0;
  }

  // totalAmt 누적
  for (let i = 0; i < seller.length; i++) {
    let person = seller[i];
    let money = amount[i] * 100;

    while (parent[person] && 0 < money) {
      const moneyToGive = Math.floor(money * 0.1);
      const moneyToHave = money - moneyToGive;

      totalAmt[person] += moneyToHave;

      person = parent[person];
      money = moneyToGive;
    }
  }

  // answer array 만들기
  const answer = [];
  for (let i = 0; i < enroll.length; i++) {
    answer.push(totalAmt[enroll[i]]);
  }
  return answer;
}
