window.addEventListener('DOMContentLoaded',function(){
    // 添加笔记
    // addNote()

    // 关闭蒙版
    turnOff()
    // 显示增加笔记盒子
    showAdd()
    
    let addNote = function () {
        let show = document.querySelector('.show')
        
        let addBox = document.querySelector('.addBox')
        let keep = addBox.querySelector('.keep')
        let titleBox = addBox.querySelector('.addtitle')

        // console.log(addBox.querySelector('.addtitle'));
        let contentBox = addBox.querySelector('.event')

        let allNote = document.querySelector('.allNote')
        let note = allNote.querySelectorAll('.note')
        let str = '';
        keep.addEventListener('click', function () {
            let title = titleBox.value
            let content = contentBox.value
            console.log(title);
            console.log(content);
            str += ` <div class="note">
                <div class="note_head">
                    <h1 class="title">${title}</h1>
                </div>
                <div class="note_fun">
                    <button class="change"><i class="iconfont icon-xiugai "></i></button>
                    
                    <button class="delete"><i class="iconfont icon-shanchu "></i></button>
                </div>
                <div class="hidden">
                    <h1>${title}</h1>
                    <p>${content}</p>
                </div>
            </div>`
            str += allNote.innerHTML;
            // for(let i=0;i<note.length;i++){
            //     let a = htmlToString(note[i]);
            //     str+=a;

            // }
            allNote.innerHTML = str;
            titleBox.value = ''
            contentBox.value = ''
            str=''
            alert("保存成功")
            // 删除笔记
            deleteNote()
            // 修改
            change()
            // 搜索
            search()
        })
      
    }
    addNote()
    // 储存
  
    // 渲染 本地存储中的笔记
    let draw=function(){
        let note=JSON.parse(localStorage.getItem('allnote'))
// console.log(note);
let str='';
note.map(function(item){
    str +=`<div class="note">
                <div class="note_head">
                    <h1 class="title">${item.title}</h1>
                </div>
                <div class="note_fun">
                    <button class="change"><i class="iconfont icon-xiugai "></i></button>
                    
                    <button class="delete"><i class="iconfont icon-shanchu "></i></button>
                </div>
                <div class="hidden">
                    <h1>${item.title}</h1>
                    <p>${item.content}</p>
                </div>
            </div>`
})

let allNote=document.querySelector('.allNote')
allNote.innerHTML=str
        // 删除笔记
        deleteNote()
        // 修改
        change()
    }
    draw()
    // 搜索
    search()
    window.addEventListener('beforeunload', function () {
        reserve()
    })

 
})