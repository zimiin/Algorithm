// 매칭 점수

function solution(word, pages) {
  const getPageInfo = (page, word) => {
    const metaRegEx = /<meta property=\"og:url\" content=\".*\"\/>/m;
    const meta = page.match(metaRegEx)[0]

    const startUrl = '<meta property="og:url" content="'.length
    const endUrl = meta.length - 3
    const url = meta.slice(startUrl, endUrl)

    const lines = page.split('\n')
    const body = lines.slice(6, lines.length - 2)

    let wordCnt = 0
    const linkTo = []

    const w = `([^a-z]| )${word.toLowerCase()}([^a-z]| )`
    const wordRegEx = new RegExp(w, 'g')
    const aTagRegEx = /<a href=\".*\">/g

    for (let line of lines) {
      line = line.toLowerCase()

      const words = line.match(wordRegEx)
      if (words) {
        wordCnt += words.length
      }

      const aTags = line.matchAll(aTagRegEx)
      for (let aTag of aTags) {
        const linkStart = '<a href="'.length
        const linkEnd = aTag[0].length - 2
        linkTo.push(aTag[0].slice(linkStart, linkEnd))
      }
    }

    return [url, { wordCnt, linkTo }]
  }

  const pageInfo = {} // url => { index, wordCnt, linkTo }
  const linkedCnt = {} // url => linked count
  const scores = {} // url => page score

  for (let i = 0; i < pages.length; i++) {
    const page = pages[i]
    const [url, info] = getPageInfo(page, word)

    info['index'] = i
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

    if (pageInfo[url] === undefined) {
      continue
    }

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