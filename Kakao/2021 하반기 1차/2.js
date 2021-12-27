let noCourses = new Map() // ex. 주문메뉴 => 주문횟수
let maxNo = new Map() // ex. 길이 => 해당 길이에 대한 최대주문횟수
let maxCourse = new Map() // ex. 길이 => 해당 길이에 대한 최대 주문된 메뉴

function countCourse(order, idx, course) {
  if (course.length > 1) {
    let strCourse = course.join('')

    if (noCourses.has(strCourse)) {
      let cur = noCourses.get(strCourse)
      noCourses.set(strCourse, cur + 1)
    } else {
      noCourses.set(strCourse, 1)
    }
  }

  for (; idx < order.length; idx++) {
    course.push(order[idx])
    countCourse(order, idx + 1, course)
    course.pop()
  }
}

function getMax(value, key, map) {
  let length = key.length

  if (maxNo.has(length)) {
    let curNo = maxNo.get(length)

    if (value > curNo) {
      maxNo.set(length, value)
      maxCourse.set(length, [key])
    } else if (value === curNo) {
      let curCourse = maxCourse.get(length)
      curCourse.push(key)
      maxCourse.set(length, curCourse)
    }
  } else {
    maxNo.set(length, value)
    maxCourse.set(length, [key])
  }
}

function solution(orders, course) {
  for (let order of orders) {
    let sortedOrder = order.split('').sort()
    countCourse(sortedOrder, 0, [])
  }

  noCourses.forEach(getMax)

  let answer = []

  for (let courseLen of course) {
    let max = maxNo.get(courseLen)
    if (max > 1) {
      let menus = maxCourse.get(courseLen)
      for (let menu of menus) {
        answer.push(menu)
      }
    }
  }

  return answer.sort();
}