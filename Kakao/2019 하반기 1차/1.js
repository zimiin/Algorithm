function solution(record) {
  let user = new Map(); // uid => nickname 형태
  let logs = []; // {uid: ..., status: Enter/Leave} 형태

  for (let no = 0; no < record.length; no++) {
    const [status, uid, nickname] = record[no].split(' ');

    if (status === 'Enter' || status === 'Change') {
      user.set(uid, nickname);
    }

    if (status !== 'Change') {
      logs.push({ uid: uid, status: status });
    }
  }

  let answer = [];

  for (let no = 0; no < logs.length; no++) {
    const nickname = user.get(logs[no].uid);

    if (logs[no].status === 'Enter') {
      answer.push(nickname + '님이 들어왔습니다.')
    } else {
      answer.push(nickname + '님이 나갔습니다.')
    }
  }

  return answer;
}