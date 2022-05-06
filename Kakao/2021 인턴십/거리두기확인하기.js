function solution(places) {
  const getArr = (place) => {
    const arr = [];
    for (row of place) {
      arr.push([...row]);
    }
    return arr;
  };

  const isSafe = (place) => {
    for (let r = 0; r < 5; r++) {
      for (let c = 0; c < 5; c++) {
        if (place[r][c] !== "P") {
          continue;
        }

        // 1칸 거리에 사람 있는지 확인
        if (c <= 3 && place[r][c + 1] === "P") {
          return 0;
        }
        if (r <= 3 && place[r + 1][c] === "P") {
          return 0;
        }

        // 2칸 직선 거리 거리두기 확인
        if (c <= 2 && place[r][c + 1] !== "X" && place[r][c + 2] === "P") {
          return 0;
        }
        if (r <= 2 && place[r + 1][c] !== "X" && place[r + 2][c] === "P") {
          return 0;
        }

        // 2칸 대각선 거리두기 확인
        // 오른쪽 위 사람 있을 때
        if (0 < r && c <= 3 && place[r - 1][c + 1] === "P") {
          if (place[r - 1][c] !== "X" || place[r][c + 1] !== "X") {
            return 0;
          }
        }
        // 오른쪽 아래 사람 있을 때
        if (r <= 3 && c <= 3 && place[r + 1][c + 1] === "P") {
          if (place[r][c + 1] !== "X" || place[r + 1][c] !== "X") {
            return 0;
          }
        }
      }
    }
    return 1;
  };

  const answer = [];
  for (place of places) {
    const placeArr = getArr(place);
    // 거리두기 여부 확인
    answer.push(isSafe(placeArr));
  }
  return answer;
}
