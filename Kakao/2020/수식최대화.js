const makeExpArray = (exp) => {
  const res = exp
    // 연산자로 분리
    .split(/([\+\-\*])/)
    .map((elem) => {
      // 숫자 문자열은 number 타입으로 변환
      if (elem !== "+" && elem !== "-" && elem !== "*") {
        return parseInt(elem);
      } else return elem;
    });
  return res;
};

const calculate = (exp, operatorOrder) => {
  const expArr = [...exp];
  for (const operator of operatorOrder) {
    while (true) {
      const operatorIdx = expArr.findIndex((elem) => elem === operator);
      // 현재 연산자 계산 완료
      if (operatorIdx === -1) break;

      const leftOperand = expArr[operatorIdx - 1];
      const rightOperand = expArr[operatorIdx + 1];
      const result =
        operator === "+"
          ? leftOperand + rightOperand
          : operator === "-"
          ? leftOperand - rightOperand
          : leftOperand * rightOperand;

      expArr.splice(operatorIdx - 1, 3, result);
    }
  }
  return expArr[0];
};

function solution(expression) {
  // 연산자 우선순위
  const operatorOrders = [
    ["+", "-", "*"],
    ["+", "*", "-"],
    ["-", "+", "*"],
    ["-", "*", "+"],
    ["*", "+", "-"],
    ["*", "-", "+"],
  ];

  // 숫자, 연산자 분리한 계산식
  const exp = makeExpArray(expression);

  // 순서대로 계산하기
  let answer = 0;
  for (const operatorOrder of operatorOrders) {
    const res = Math.abs(calculate(exp, operatorOrder));
    if (answer < res) {
      answer = res;
    }
  }
  return answer;
}
