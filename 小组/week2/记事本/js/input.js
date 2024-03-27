let search = function () {
    // console.log(111);
    check()
    let searchBox = document.querySelector('.search')
    let input = searchBox.querySelector('input')
    let hidden = document.querySelectorAll('.hidden')
    let note = {};
    let allNote = [];
    for (let i = 0; i < hidden.length; i++) {
        let note = {};
        let title = hidden[i].querySelector('h1').textContent
        let content = hidden[i].querySelector('p').textContent
        note.index = i
        note.title = title
        note.content = content
        allNote.push(note);
    }
    let box = document.querySelector('.sea_content')
    input.addEventListener('input', function () {
        // console.log(111);
        box.innerHTML = ''
        let key = input.value;
        if(key==''){
            box.style.display = 'none'
            box.innerHTML=''
            return
        }
        // console.log(key);
        allNote.map(function (item) {
            const titleMatchIndex = item.title.indexOf(key);
            const contentMatchIndex = item.content.indexOf(key);
            let {title,content}=item
            if(titleMatchIndex!==-1){
                box.style.display='block'
                // let regex = new RegExp(key, 'g');
                let regex = new RegExp("(.{0,3}" + key + ".{0,3})", "g");
                let matches = title.match(regex)
                const parts = matches[0].split(key)
                // console.log(parts);
              let li=document.createElement('li')
              let str='';
                parts.forEach(function(part,index) {
                    if (index == parts.length - 1) { str += `<span>${part}</span><span class="nature">title</span>` }
                    else { str += `<span>${part}</span><span class="key">${key}</span>` }
                });
                if (key == matches[0]) { 
                    console.log(1); str += `<p class="index">${item.index}</p>` }
                str += `<p class="index">${item.index}</p>`
                li.innerHTML=str;
                box.appendChild(li)
            }
            if(contentMatchIndex!==-1){
                box.style.display = 'block'
                // let regex = new RegExp(key, 'g');
                let regex = new RegExp("(.{0,10}" + key + ".{0,10})", "g");
                let matches = content.match(regex)
                const parts = matches[0].split(key)
                console.log(parts);
                let li = document.createElement('li')
                let str = '';
                parts.forEach(function (part, index) {
                    if (index == parts.length - 1) { str += `<span>${part}</span><span class="nature">content</span>` }
                    else { str += `<span>${part}</span><span class="key">${key}</span>` }
                });
                if (key == matches[0]) { console.log(1);
                    str += `<p class="index">${item.index}</p>` }
                str += `<p class="index">${item.index}</p>`
                li.innerHTML = str;
                box.appendChild(li)
                check()
                // console.log("Found matches:", matches[0]);
            }
           
        })

    })
    box.style.display = 'none'
}
let check = function () {
// console.log(111);
    let box = document.querySelector('.sea_content')
    let li = box.querySelectorAll('li')
    // console.log(li);
    for (let i = 0; i < li.length; i++) {
        li[i].addEventListener('click', function () {
            console.log(111);
            let show = document.querySelector('.show')

            let showBox = show.querySelector('.showBox')
            let keep = showBox.querySelector('.keep')
            let index = li[i].querySelector('.index').textContent
            let allNote = document.querySelector('.allNote')
            let note = allNote.querySelectorAll('.note')
            show.style.display = 'flex';
            showBox.style.display = 'flex';
            let hidden = note[index].querySelector('.hidden')
            let titleBox = showBox.querySelector('.title_cont')
            let contentBox = showBox.querySelector('.re_event')
            titleBox.value = hidden.querySelector('h1').textContent
            contentBox.value = hidden.querySelector('p').textContent
            keep.addEventListener('click', function () {

                let title = titleBox.value
                let content = contentBox.value
                // console.log(title);
                let noteFun = hidden.previousElementSibling
                let head = noteFun.previousElementSibling
                head.querySelector('h1').innerText = title
                hidden.querySelector('h1').innerText = title
                hidden.querySelector('p').innerText = content
                alert("保存成功")
            })
        })
    }
}
