(function () {
    const STAR_COUNT = 300 // 星星的数量
    const MIN_STAR_SIZE = 2 // 星星的最小尺寸
    const MAX_STAR_SIZE = 8 // 星星的最大尺寸

    const container = document.querySelector('#sky')
    const collection = document.createDocumentFragment()
    for (let index = 0; index < STAR_COUNT; index++) {
      const star = document.createElement('span')
      star.setAttribute('class', 'star')
      const width = random(MIN_STAR_SIZE, MAX_STAR_SIZE)
      const height = width
      const top = random(0, 100)
      const left = random(0, 100)
      const duration = random(0.5, 1)
      const delay = random(0, 0.75)
      star.style.cssText = `width: ${width}px; height: ${height}px;
      left: ${left}%; top: ${top}%; 
      animation-duration: ${duration}s; animation-delay: ${delay}s`
      collection.appendChild(star)
    }
    container.appendChild(collection)
})()