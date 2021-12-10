function solution(new_id) {
    let answer;
    
    // 1단계
    answer = new_id.toLowerCase();
    console.log(answer);
    
    // 2단계
    const validCharRegex = /[a-z]|[0-9]|[-_.]/g;
    answer = answer.match(validCharRegex).join('');
    console.log(answer);
    
    // 3단계
    const dotsRegex = /\.+/g;
    answer = answer.replace(dotsRegex, '.');
    console.log(answer);
    
    // 4단계
    const firstLastDotRegex = /^\.|\.$/g;
    answer = answer.replace(firstLastDotRegex, '');
    console.log('len', answer.length, answer);
    
    // 5단계
    if (answer.length === 0) {
        answer = 'a';
    }
    console.log(answer);
    
    // 6단계
    const lastDotRegex = /\.$/g;
    answer = answer.slice(0, 15);
    answer = answer.replace(lastDotRegex, '');
    console.log(answer);
    
    // 7단계
    for (let i = answer.length - 1; i < 2; i++) {
        answer += answer[i];
    }
    console.log(answer);
    
    return answer;
}