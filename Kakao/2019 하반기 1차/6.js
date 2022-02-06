// 매칭 점수

function solution(word, pages) {
  const getPageInfo = (page) => {
    const metaRegEx = /<meta property=\"og:url\" content=.*\/>/gm;
    const meta = page.match(metaRegEx)


  }

  const pageInfo = {} // url => { index, wordCnt, linkTo }
  const linkedCnt = {} // url => linked count
  const scores = {} // url => page score

  for (let page of pages) {
    const [url, info] = getPageInfo(page)
    pageInfo[url] = info

    scores[url] = pageInfo[url].wordCnt

    for (let link of pageInfo[url].linkTo) {
      linkedCnt[link] = linkedCnt[link] || 0
      linkedCnt[link]++
    }
  }

  // 탐색
  const q = []

  for (let url in linkedCnt) {
    if (linkedCnt[url] === 0) {
      q.push(url)
    }
  }

  while (0 < q.length) {
    const url = q.shift()
    const linkTo = pageInfo[url].linkTo
    const linkScore = pageInfo[url].wordCnt / linkTo.length

    for (let link of linkTo) {
      scores[link] += linkScore

      linkedCnt[link]--
      if (linkedCnt[link] === 0) {
        q.push(link)
      }
    }
  }

  let maxIdx = -1
  let maxScore = -1

  for (let url in scores) {
    const idx = pageInfo[url].index

    if (maxScore < scores[url]) {
      maxScore = scores[url]
      maxIdx = idx
    } else if (maxScore === scores[url]) {
      if (idx < maxIdx) {
        maxIdx = idx
      }
    }
  }

  return maxIdx
}